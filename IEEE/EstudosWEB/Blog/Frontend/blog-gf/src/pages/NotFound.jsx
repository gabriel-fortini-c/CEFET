import React from "react";
import { Link } from "react-router-dom";

function NotFoundPage() {
  return (
    // Com a Solução 1 do layout (flex-1 no <main>), podemos
    // usar h-full para preencher todo o espaço disponível.
    <div className="h-full flex flex-col items-center justify-center text-center p-6">
      {/* Usei uma das suas cores para o 404 */}
      <h1 className="text-8xl font-bold text-[rgb(177,151,0)]">404</h1>

      <h2 className="text-3xl font-semibold text-gray-800 mt-4 mb-6">
        Página Não Encontrada
      </h2>

      <p className="text-gray-500 mb-8 max-w-sm">
        Desculpe, a página que você está tentando acessar não existe ou foi
        movida.
      </p>

      {/* Botão para voltar à Home (usei sua cor amarela) */}
      <Link
        to="/"
        className="bg-[rgb(255,217,0)] hover:text-white hover:bg-black text-black font-bold py-3 px-6 rounded-lg text-lg focus:outline-none focus:ring-2 focus:ring-amber-300"
      >
        Voltar para a Home
      </Link>
    </div>
  );
}

export default NotFoundPage;
