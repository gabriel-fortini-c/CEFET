import React, { use, useState } from "react";
import { useAuth } from "../context/AuthContext";
import { useNavigate, Link } from "react-router-dom";
import axios from "axios";

function Register() {
  // Estados do Formulário
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [confirmPassword, setConfirmPassword] = useState("");
  const [error, setError] = useState(null);

  // Hooks
  const { login } = useAuth();
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError(null);

    // Validação: Senhas são iguais?
    if (password !== confirmPassword) {
      setError("Senha invállida.");
      return;
    }

    try {
      // Validação: O usuário já existe?
      // GET para verificar se o email já está em uso
      const checkUser = await axios.get(
        `http://localhost:3001/users?email=${email}`
      );
      if (checkUser.data.length > 0) {
        setError("Este email já está em uso.");
        return;
      }

      // Criar novo usuário
      const newUser = {
        name,
        email,
        password,
      };

      // Post na API
      const response = await axios.post("http://localhost:3001/users", newUser);

      // 5. Auto-Login!
      login({
        id: response.data.id,
        email: response.data.email,
        name: response.data.name,
      });
      setTimeout(() => navigate("/"), 1000);
    } catch (err) {
      console.error("Erro no registro:", err);
      setError("Ocorreu um erro ao tentar se registrar.");
    }
  };

  return (
    <div className="h-full flex flex-col items-center md:justify-center">
      <form
        onSubmit={handleSubmit}
        className="flex flex-col items-center w-full h-full bg-white text-black p-4 gap-y-3
                 md:h-auto md:max-w-[450px] md:border-2 md:rounded-[20px] md:shadow-lg"
      >
        <h2 className="self-center text-2xl font-bold my-5">Cadastrar</h2>

        {error && (
          <div className="bg-red-100 border border-red-400 text-red-700 px-4 py-3 rounded mb-4">
            {error}
          </div>
        )}

        {/* Campo de Nome */}
        <div className="self-center p-2">
          <label
            className="block text-gray-700 text-sm font-bold mb-2"
            htmlFor="name"
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
        <div className="self-center p-2">
          <label
            htmlFor="email"
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

        {/* Campo de Senha */}
        <div className="self-center p-2">
          <label
            htmlFor="password"
            className="block text-gray-700 text-sm font-bold mb-2"
          >
            Senha
          </label>
          <input
            type="password"
            id="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            required
            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
          />
        </div>

        {/* Campo de Confirmar Senha */}
        <div className="self-center p-2">
          <label
            htmlFor="confirmPassword"
            className="block text-gray-700 text-sm font-bold mb-2"
          >
            Confirmar Senha
          </label>
          <input
            type="password"
            id="confirmPassword"
            value={confirmPassword}
            onChange={(e) => setConfirmPassword(e.target.value)}
            required
            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
          />
        </div>

        {/* Botão de Enviar */}
        <button
          type="submit"
          className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-white font-bold py-2 px-4 rounded w-full focus:outline-none focus:ring-2 focus:ring-amber-300"
        >
          Cadastrar
        </button>

        {/* Link para Login */}
        <div className="flex flex-row my-3">
          <p className="justify-center">
            Já tem uma conta? Faça
            <Link
              to="/login"
              className="ml-1 underline hover:underline-amber hover:text-[rgb(255,217,0)]"
            >
              Login
            </Link>
            !
          </p>
        </div>
      </form>
    </div>
  );
}

export default Register;
