import { Link, useNavigate, useLocation } from "react-router-dom";
import { useAuth } from "../context/AuthContext";
import React, { useState } from "react";

function Header() {
  const { authUser, logout } = useAuth();
  const navigate = useNavigate();
  const location = useLocation();

  // Estado para controlar o menu mobile
  const [isMenuOpen, setIsMenuOpen] = useState(false);

  const handleLogout = () => {
    logout();
    navigate("/");
    setIsMenuOpen(false); // Fecha o menu responsivo
  };

  return (
    <header className="relative flex w-full bg-[rgb(0,0,0)] justify-between items-center">
      <h1 className="p-4 text-2xl text-[rgb(255,217,0)] font-bold">
        Meu Blog Pessoal
      </h1>

      {/* 4. Botão Hambúrguer (SÓ APARECE EM TELAS PEQUENAS) */}
      {/* 'md:hidden' faz ele DESAPARECER em telas médias (md) ou maiores */}
      <button
        onClick={() => setIsMenuOpen(!isMenuOpen)}
        className="md:hidden text-white p-2"
        aria-label="Abrir menu"
      >
        <div className="w-6 h-0.5 bg-white mb-1.5"></div>
        <div className="w-6 h-0.5 bg-white mb-1.5"></div>
        <div className="w-6 h-0.5 bg-white mb-1.5"></div>
      </button>

      {/* 5. Navegação Principal (SÓ APARECE EM TELAS GRANDES) */}
      {/* 'hidden' esconde por padrão (mobile) */}
      {/* 'md:flex' faz aparecer como flex em telas médias ou maiores */}
      <div className="hidden md:flex gap-8 p-4 text-black text-[20px] items-center">
        {location.pathname !== "/" && (
          <Link
            to="/"
            className="px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
          >
            Home
          </Link>
        )}
        {authUser ? (
          // caso esteja logado
          <>
            <Link
              to="/create-post"
              className="px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
            >
              Criar Post
            </Link>
            <Link
              to="/profile"
              className="hidden sm:block px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
            >
              {authUser.name}
            </Link>
            <button
              onClick={handleLogout}
              className="px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
            >
              Sair
            </button>
          </>
        ) : (
          // caso esteja deslogado
          <>
            <Link
              to="/login"
              className="px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
            >
              Login
            </Link>
            <Link
              to="/register"
              className="px-4 text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)]"
            >
              Cadastro
            </Link>
          </>
        )}
      </div>

      {/* 6. Menu Mobile Dropdown (SÓ APARECE QUANDO isMenuOpen é true) */}
      {/* Este menu é posicionado 'absolute' logo abaixo do header */}
      {
        <div
          className={`absolute top-full left-0 w-full bg-[rgb(177,151,0)] flex flex-col items-center gap-4 p-4 md:hidden z-10
                  transition-all duration-500 ease-in-out
                  ${
                    isMenuOpen
                      ? "opacity-100 translate-y-0 visible" // Estado ABERTO
                      : "opacity-0 -translate-y-full invisible" // Estado FECHADO
                  }`}
        >
          {location.pathname !== "/" && (
            <Link
              to="/"
              onClick={() => setIsMenuOpen(false)} // Fecha o menu ao clicar
              className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)] bg-[#000000] rounded-[4px]"
            >
              Home
            </Link>
          )}
          {authUser ? (
            <>
              <Link
                to="/profile"
                onClick={() => setIsMenuOpen(false)}
                className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(255,255,255)] bg-[#000000] rounded-[4px]"
              >
                Olá, {authUser.name}
              </Link>
              <Link
                to="/create-post"
                onClick={() => setIsMenuOpen(false)}
                className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)] bg-[#000000] rounded-[4px]"
              >
                Criar Post
              </Link>
              <button
                onClick={handleLogout} // handleLogout já fecha o menu
                className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)] bg-[#000000] rounded-[4px]"
              >
                Sair
              </button>
            </>
          ) : (
            <>
              <Link
                to="/login"
                onClick={() => setIsMenuOpen(false)}
                className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)] bg-[#000000] rounded-[4px]"
              >
                Login
              </Link>
              <Link
                to="/register"
                onClick={() => setIsMenuOpen(false)}
                className="px-4 py-2 w-full text-center text-[rgb(255,217,0)] hover:text-[rgb(147,125,0)] bg-[#000000] rounded-[4px]"
              >
                Cadastro
              </Link>
            </>
          )}
        </div>
      }
    </header>
  );
}

export default Header;
