import React, { useState, useEffect } from "react";
import { useAuth } from "../context/AuthContext";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import Modal from "../components/Modal";
import PostDate from "../components/PostDate";

function Home() {
  const [posts, setPosts] = useState([]);
  const { authUser } = useAuth();
  const navigate = useNavigate();

  // Criar os estados para controlar o modal
  const [isModalOpen, setIsModalOpen] = useState(false);

  // Precisamos "lembrar" qual post estamos prestes a excluir quando o modal for aberto.
  const [postToDelete, setPostToDelete] = useState(null);

  useEffect(() => {
    const fetchPosts = async () => {
      try {
        const postsResponse = await axios.get("http://localhost:3001/posts");
        const usersResponse = await axios.get("http://localhost:3001/users");
        const users = usersResponse.data;

        const postsWithUsers = postsResponse.data.map((post) => ({
          ...post,
          user: users.find((u) => u.id === post.userId),
        }));

        setPosts(postsWithUsers);
      } catch (error) {
        console.error("Erro ao buscar post:", error);
      }
    };

    fetchPosts();
  }, []);

  // Esta função *apenas abre o modal* e armazena o post
  const handleDeleteClick = (post) => {
    setPostToDelete(post); // Lembra qual post é
    setIsModalOpen(true); // Abre o modal
  };

  // Esta função faz a exclusão de fato (será chamada pelo botão "Confirmar" no modal)
  const confirmDelete = async () => {
    if (!postToDelete) return; // Segurança

    try {
      await axios.delete(`http://localhost:3001/posts/${postToDelete.id}`);

      // Atualiza a lista de posts na tela
      setPosts(posts.filter((post) => post.id !== postToDelete.id));

      // Fecha o modal e limpa o estado
      setIsModalOpen(false);
      setPostToDelete(null);
    } catch (error) {
      console.error("Erro ao excluir o post: ", error);
      // Aqui você poderia mostrar um erro dentro do modal, mas por enquanto vamos só fechar
      setIsModalOpen(false);
      setPostToDelete(null);
    }
  };

  const handleEdit = (postId) => {
    navigate(`/edit-post/${postId}`);
  };

  return (
    <div className="max-w-4xl mx-auto p-4 md:p-8">
      <h2 className="text-3xl font-bold text-gray-900 mb-6">Últimos Posts</h2>
      {posts.length === 0 ? (
        <p>Nenhum post encontrado.</p>
      ) : (
        <ul className="list-none m-0 p-0 flex flex-col gap-6 ">
          {posts.map((post) => (
            <div className="p-2 bg-[rgb(255,217,0)] rounded-[5px]">
              <li
                key={post.id}
                className="px-8 py-6 border-5 border-black bg-white rounded-[5px]"
              >
                <div className="text-sm text-black mb-4 gap-x-4">
                  <span>
                    <strong> Por {post.user?.name || "Desconhecido"} - </strong>
                  </span>
                  <PostDate isoDate={post.createdAt} />
                </div>
                <h3 className="text-2xl p-2 border-b border-gray-300">
                  {post.title}
                </h3>
                <p className="text-gray my-6 p-4 rounded-[10px] bg-[rgb(193,193,193)]">
                  {post.content}
                </p>

                {/* Botões de excluir */}
                {authUser && authUser.id === post.userId && (
                  <div className="flex justify-end gap-x-8">
                    <button
                      onClick={() => handleEdit(post.id)}
                      className="py-1 px-4 bg-white hover:bg-gray-300 focus:outline-none focus:ring-1 focus:ring-amber-300"
                    >
                      Editar
                    </button>
                    <button
                      onClick={() => handleDeleteClick(post)}
                      className="py-1 px-4 bg-white hover:bg-gray-300 focus:outline-none focus:ring-1 focus:ring-amber-300"
                    >
                      Excluir
                    </button>
                  </div>
                )}
              </li>
            </div>
          ))}
        </ul>
      )}

      {/* Ele fica "invisível" (null) até isModalOpen ser true */}
      <Modal isOpen={isModalOpen} onClose={() => setIsModalOpen(false)}>
        <div className="text-center">
          <h3 className="text-2xl font-bold mb-4">Confirmar Exclusão</h3>
          <p className="text-gray-700 mb-6">
            Tem certeza que deseja excluir o post
            <strong className="mx-1">"{postToDelete?.title}"</strong>? Esta ação
            é permanente.
          </p>
          <div className="flex justify-center gap-4">
            {/* Botão de Cancelar */}
            <button
              onClick={() => setIsModalOpen(false)}
              className="px-6 py-2 bg-gray-300 text-gray-800 rounded-md hover:bg-gray-400"
            >
              Cancelar
            </button>
            {/* Botão de Confirmar */}
            <button
              onClick={confirmDelete}
              className="px-6 py-2 bg-red-600 text-white rounded-md hover:bg-red-700"
            >
              Excluir
            </button>
          </div>
        </div>
      </Modal>
    </div>
  );
}

export default Home;
