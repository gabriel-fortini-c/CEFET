import React from "react";
import { format, parseISO } from "date-fns";
import { ptBR } from "date-fns/locale";

function PostDate({ isoDate }) {
  if (!isoDate) return null;

  try {
    // Converter o string ISO para um objeto Date
    const date = parseISO(isoDate);

    // Formatar o objeto Date para o formato que queremos
    // d 'de' MMMM 'de' yyyy  ->  26 'de' outubro 'de' 2025
    const formattedDate = format(date, "d 'de' MMMM 'de' yyyy", {
      locale: ptBR, //Usar o idioma português
    });

    // Retorna a data formatada
    return (
      <span className="text-sm text-black mb-4 ml-1">{formattedDate}</span>
    );
  } catch (err) {
    console.error("Erro ao formatar data:", error);
    return <span className="text-sm text-red-500">Data inválida</span>;
  }
}

export default PostDate;
