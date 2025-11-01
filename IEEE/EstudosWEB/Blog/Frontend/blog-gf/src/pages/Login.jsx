import React, { useState } from "react";
import { useAuth } from "../context/AuthContext";
import { useNavigate, Link } from "react-router-dom";
import axios from "axios";

function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState(null);

  const { login } = useAuth();
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError(null);

    try {
      const response = await axios.get("http://localhost:3001/users", {
        params: {
          email: email,
          password: password,
        },
      });

      if (response.data.length > 0) {
        const user = response.data[0];

        login({ id: user.id, email: user.email, name: user.name });

        navigate("/");
      } else {
        setError("Email ou senha inválidos.");
      }
    } catch (err) {
      console.error("Erro no login", err);
      setError("Ocorreu um erro ao tentar fazer login. Tente novamente.");
    }
  };

  return (
    <div className="h-full flex flex-col items-center md:justify-center">
      <form
        onSubmit={handleSubmit}
        className="flex flex-col items-center w-full h-full bg-white text-black p-4 gap-y-5
                 md:h-auto md:max-w-[450px] md:border-2 md:rounded-[20px] md:shadow-lg"
      >
        <h2 className="self-center text-2xl font-bold my-5">Login</h2>

        {/* Mostra mensagens de erro */}
        {error && (
          <div className="bg-red-100 border border-red-400 text-red-700 px-4 py-3 rounded mb-4">
            {error}
          </div>
        )}

        {/* Campo de Email */}
        <div className="self-center p-2">
          <label className="block text-gray-700 text-sm font-bold mb-2">
            Email
          </label>
          <input
            type="email"
            id="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            required
            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:ring-1 focus:ring-gray-300"
          ></input>
        </div>

        {/* Campo de Senha */}
        <div className="self-center p-2">
          <label className="block text-gray-700 text-sm font-bold mb-2">
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

        <div className="flex flex-row my-3">
          <p className="justify-center">Não tem conta? Clique em</p>
          <Link
            to="/register"
            className="ml-1 underline hover:underline-amber hover:text-[rgb(255,217,0)]"
          >
            cadastro
          </Link>
          <p>!</p>
        </div>

        {/* Botão de Enviar */}
        <button
          type="submit"
          className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-white font-bold py-2 px-4 rounded w-full focus:outline-none focus:ring-2 focus:ring-amber-300"
        >
          Entrar
        </button>

        {/* Link para registro (opcional, podemos fazer depois) */}
        {/* <p className="text-center text-gray-600 text-sm mt-4">
          Não tem uma conta? <Link to="/register" className="text-blue-500 hover:underline">Registre-se</Link>
        </p>
        */}
      </form>
    </div>
  );
}

export default Login;
