import React, { useState, useEffect } from "react";
import ReactDOM from "react-dom";

// Este componente recebe:
// - isOpen: (boolean) Se o modal deve ou não estar visível.
// - onClose: (função) O que fazer quando o usuário quiser fechar (ex: clicar fora).
// - children: O conteúdo a ser mostrado dentro do modal (ex: o texto e os botões).
function Modal({ isOpen, onClose, children }) {
  // Se não estiver aberto, não renderiza nada (null).
  if (!isOpen) return null;

  // Lógica de Acessibilidade (Bônus): Fechar com a tecla 'Escape'
  // Lógica de Acessibilidade (Bônus): Fechar com a tecla 'Escape'
  useEffect(() => {
    const handleEscape = (e) => {
      if (e.key === "Escape") {
        onClose();
      }
    };

    // Adiciona o ouvinte
    document.addEventListener("keydown", handleEscape);

    // Limpa o ouvinte quando o modal for fechado
    return () => {
      document.removeEventListener("keydown", handleEscape);
    };
  }, [onClose]);

  // O Portal!
  // ReactDOM.createPortal(O_QUE_RENDERIZAR, ONDE_RENDERIZAR)
  return ReactDOM.createPortal(
    // O Backdrop (fundo escuro)
    <div
      className="fixed inset-0 bg-black bg-opacity-70 z-40 flex justify-center items-center"
      onClick={onClose} // Clicar fora (no backdrop) fecha o modal
    >
      {/* O "Card" do Modal (conteúdo branco) */}
      <div className="bg-[rgb(255,217,0)] p-6 rounded-lg shadow-xl z-50 w-full max-w-md">
        <div
          // Impede que cliques DENTRO do modal o fechem
          onClick={(e) => e.stopPropagation()}
          className="bg-white p-6 rounded-lg shadow-xl z-50 w-full max-w-md"
        >
          {children} {/* Aqui entra o seu conteúdo (ex: "Tem certeza?") */}
        </div>
      </div>
    </div>,
    document.getElementById("modal-root") // O "local de teleporte"
  );
}

export default Modal;
