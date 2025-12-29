import { useNavigate, useParams } from "react-router-dom";
import React, { useEffect, useState } from "react";
import { useAuth } from "../context/AuthContext";
import axios from "axios";

function EditPost() {
  // Hooks
  const { postId } = useParams();
  const navigate = useNavigate();
  const { authUser } = useAuth();

  // Estados do Formulário
  const [title, setTitle] = useState("");
  const [content, setContent] = useState("");

  // Estados da Página
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    // Só executa se tivermos o ID do post e o usuário logado
    if (!postId || !authUser) return;

    const fetchPostsData = async () => {
      try {
        setLoading(true);
        const response = await axios.get(
          `http://localhost:3001/posts/${postId}`
        );
        const post = response.data;

        // 5. VERIFICAÇÃO DE AUTORIZAÇÃO
        // O usuário logado é o dono deste post?

        if (post.userId !== authUser.id) {
          // Não é o dono!
          setError("Você não tem permissão para editar este post.");
          setTimeout(() => navigate("/"), 3000);
          return;
        }

        // É o dono. Preenche o formulário com os dados.
        setTitle(post.title);
        setContent(post.content);
      } catch {
        console.error("Erro ao buscar post:", err);
        setError("Não foi possível carregar o post.");
      } finally {
        setLoading(false);
      }
    };

    fetchPostsData();
  }, [postId, authUser, navigate]); // Dependências do useEffect

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError(null);

    const updatedPost = {
      title: title,
      content: content,
    };

    try {
      // Usamos PATCH para atualizar só os campos enviados
      await axios.patch(`http://localhost:3001/posts/${postId}`, updatedPost);

      // Sucesso!
      navigate("/");
    } catch {
      console.error("Erro ao atualizar post:", err);
      setError("Falha ao salvar as alterações. Tente novamente.");
    }
  };

  // Renderização

  // Estado de Carregamento (Loading)
  if (loading) {
    return <div className="text-center py-10">Carregando dados do post...</div>;
  }

  // Estado de Erro (seja de carregar ou de permissão)
  if (error) {
    return (
      <div className="text-center py-10 text-red-600 font-bold">{error}</div>
    );
  }

  return (
    <div className="flex flex-col items-center py-10">
      <form
        onSubmit={handleSubmit}
        className="bg-white p-8 rounded-lg shadow-md w-full max-w-2xl"
      >
        <h2 className="self-center text-2xl font-bold my-5">Editar Post</h2>

        {/* Mostra erros de SUBMISSÃO (diferente do erro de carregar) */}
        {error && (
          <div className="bg-red-100 border border-red-400 text-red-700 px-4 py-3 rounded mb-4">
            {error}
          </div>
        )}

        {/* Campo de Título */}
        <div className="mb-4">
          <label className="block text-gray-700 text-sm font-bold mb-2">
            Título
          </label>
          <input
            type="text"
            id="title"
            value={title}
            onChange={(e) => setTitle(e.target.value)}
            required
            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
          />
        </div>

        {/* Campo de Conteúdo */}
        <label className="block text-gray-700 text-sm font-bold mb-2">
          Conteúdo
        </label>
        <textarea
          id="content"
          value={content}
          onChange={(e) => setContent(e.target.value)}
          required
          rows={10}
          className="mb-6 shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
        />

        {/* Botão de Enviar */}
        <button
          type="submit"
          className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-white font-bold py-2 px-4 rounded w-full focus:outline-none focus:ring-2 focus:ring-amber-300"
        >
          Salvar Alterações
        </button>
      </form>
    </div>
  );
}

export default EditPost;
