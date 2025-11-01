import React, { useState } from "react";
import { useAuth } from "../context/AuthContext";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import Modal from "../components/Modal";

function Profile() {
  // Hooks
  const { authUser, login, logout } = useAuth();
  const navigate = useNavigate();

  // Criar os estados para controlar o modal
  const [isModalOpen, setIsModalOpen] = useState(false);

  // Estados do Formulário de Update
  const [name, setName] = useState(authUser.name);
  const [email, setEmail] = useState(authUser.email);

  // Estados de Feedabck
  const [success, setSuccess] = useState(null);
  const [error, setError] = useState(null);

  // Lógica de UPDATE (U)
  const handleUpdate = async (e) => {
    e.preventDefault();
    setError(null);
    setSuccess(null);

    const updatedUser = {
      name: name,
      email: email,
    };

    try {
      // Enviar a atualização para a API
      const response = await axios.patch(
        `http://localhost:3001/users/${authUser.id}`,
        updatedUser
      );

      // ATUALIZAR O ESTADO GLOBAL! Se não fizermos isso, o Header continuará mostrando o nome antigo.
      login(response.data);

      setSuccess("Perfil atualizado com sucesso!");

      setTimeout(() => navigate("/"), 750);
    } catch (err) {
      console.error("Erro ao atualizar o perfil.", err);
      setError("Não foi possível atualizar o perfil. Tente novamente.");
    }
  };

  // Lógica de DELETE (D)
  // Esta função *apenas abre o modal* e armazena o post
  const handleDeleteClick = () => {
    setIsModalOpen(true); // Abre o modal
  };

  // Esta função faz a exclusão de fato (será chamada pelo botão "Confirmar" no modal)
  const confirmDelete = async () => {
    try {
      // Deletar o usuário da API
      await axios.delete(`http://localhost:3001/users/${authUser.id}`);

      setSuccess("Conta deletada com sucesso!");

      // Fazer logout
      logout();

      // Fecha o modal
      setIsModalOpen(false);

      navigate("/");
    } catch (err) {
      console.error("Erro ao excluir conta:", err);
      setError("Não foi possível excluir sua conta. Tente novamente.");
      setIsModalOpen(false);
    }
  };

  return (
    <div className="max-w-4xl mx-auto p-4 md:p-8">
      {/* --- Formulário de UPDATE --- */}
      <div className="bg-white p-8 rounded-lg shadow-md w-full mb-8">
        <h2 className="text-2xl font-bold mb-6 text-center">Editar Perfil</h2>

        {/* --- Mensagens de erro e de sucesso --- */}
        {success && (
          <div className="bg-green-100 text-green-700 p-3 rounded mb-4">
            {success}
          </div>
        )}
        {error && (
          <div className="bg-red-100 text-red-700 p-3 rounded mb-4">
            {error}
          </div>
        )}

        <form
          onSubmit={handleUpdate}
          className="flex flex-col p-4 gap-y-5 bg-white text-black"
        >
          {/* Campo de Nome */}
          <div>
            <label
              htlmFor="name"
              className="block text-gray-700 text-sm font-bold mb-2"
            >
              Nome
            </label>
            <input
              type="text"
              id="name"
              value={name}
              onChange={(e) => setName(e.target.value)}
              required
              className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
            />
          </div>

          {/* Campo de Email */}
          <div>
            <label
              htlmFor="email"
              className="block text-gray-700 text-sm font-bold mb-2"
            >
              Email
            </label>
            <input
              type="email"
              id="email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
              className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
            />
          </div>

          <button
            type="submit"
            className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-white font-bold py-2 px-4 rounded w-full focus:outline-none focus:ring-2 focus:ring-amber-300"
          >
            Salvar Alterações
          </button>
        </form>
      </div>

      {/* --- Seção de DELETE ("Zona de Perigo") --- */}
      <div className="bg-red-50 border-l-4 border-red-500 p-6 rounded-lg shadow-md w-full">
        <h3 className="text-xl font-bold text-red-800 mb-4">Zona de Perigo</h3>
        <p className="text-red-700 mb-4">
          Excluir sua conta é uma ação permanente e não pode ser desfeita.
        </p>
        <button
          onClick={() => handleDeleteClick()}
          className="bg-red-600 hover:bg-red-800 text-white font-bold py-2 px-4 rounded"
        >
          Excluir minha conta
        </button>
      </div>

      <Modal isOpen={isModalOpen} onClose={() => setIsModalOpen(false)}>
        <div className="text-center">
          <h3 className="text-2xl font-bold mb-4">Confirmar Exclusão</h3>
          <p className="text-gray-700 mb-6">
            Tem certeza que deseja excluir sua conta
            <strong className="mx-1">"{name}"</strong>? Esta ação é permanente.
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

export default Profile;
