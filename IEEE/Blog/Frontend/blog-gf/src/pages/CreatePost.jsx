import React, { useState } from "react";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { useAuth } from "../context/AuthContext";

function CreatePost() {
  const [title, setTitle] = useState("");
  const [content, setContent] = useState("");
  const [error, setError] = useState(null);

  const { authUser } = useAuth();
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError(null);

    if (!authUser) {
      setError("Você precisa estar logado para criar um post.");
      return;
    }

    const newPost = {
      title: title,
      content: content,
      userId: authUser.id,
      createdAt: new Date().toISOString(),
    };

    try {
      await axios.post("http://localhost:3001/posts", newPost);

      navigate("/");
    } catch (err) {
      console.log("Erro ao criar post:", err);
      setError("Ocorreuum erro ao salvar seu post.");
    }
  };

  return (
    <div className="flex flex-col items-center py-10">
      <form
        onSubmit={handleSubmit}
        className="bg-white p-8 rounded-lg shadow-md w-full max-w-2xl"
      >
        <h2 className="self-center text-2xl font-bold my-5">Criar Novo Post</h2>

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
        <div className="mb-6">
          <label className="block text-sm mb-2 font-bold text-gray-700">
            Conteúdo
          </label>
          <textarea
            id="content"
            value={content}
            onChange={(e) => setContent(e.target.value)}
            required
            rows={10}
            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
          />
        </div>

        {/* Botão de Enviar */}
        <button
          type="submit"
          className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-white font-bold py-2 px-4 rounded w-full focus:outline-none focus:ring-2 focus:ring-amber-300"
        >
          Publicar
        </button>
      </form>
    </div>
  );
}

export default CreatePost;
