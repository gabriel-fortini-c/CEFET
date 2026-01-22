import { useState } from "react";
import Cell from "./components/Cell";
import WinningMessage from "./components/WinningMessage";

function App() {
  const [isCircleTurn, setIsCircleTurn] = useState(false); // false = X, true = O
  const [board, setBoard] = useState(Array(9).fill(null));
  const [winnerMessage, setWinnerMessage] = useState("");
  const [gameOver, setGameOver] = useState(false);

  const winningCombinations = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];

  const checkForWin = (boardToCheck, currentPlayer) => {
    return winningCombinations.some((combination) =>
      combination.every((index) => boardToCheck[index] === currentPlayer)
    );
  };

  const checkForDraw = (boardToCheck) => {
    return boardToCheck.every((cell) => cell !== null);
  };

  const endGame = (isDraw, currentPlayer) => {
    if (isDraw) {
      setWinnerMessage("Empate!");
    } else {
      // se não for empate, currentPlayer venceu
      setWinnerMessage(currentPlayer === "circle" ? "O Venceu!" : "X Venceu!");
    }
    setGameOver(true);
  };

  const resetGame = () => {
    setBoard(Array(9).fill(null));
    setIsCircleTurn(false);
    setWinnerMessage("");
    setGameOver(false);
  };

  const handlePlay = (index) => {
    if (board[index] !== null) return; // celula ocupada

    const currentPlayer = isCircleTurn ? "circle" : "x";
    const newBoard = [...board];
    newBoard[index] = currentPlayer;

    setBoard(newBoard);

    // checar vitória / empate usando newBoard (não o board antigo)
    const isWin = checkForWin(newBoard, currentPlayer);
    if (isWin) {
      endGame(false, currentPlayer);
      return; // importantíssimo: parar aqui
    }

    const isDraw = checkForDraw(newBoard);
    if (isDraw) {
      endGame(true, null);
      return;
    }

    // só troca de turno se não houve fim
    setIsCircleTurn((prev) => !prev);
  };

  return (
    <div className="relative w-full h-screen flex items-center justify-center">
      {/* Turno em cima */}
      <div className="absolute top-4 text-white text-xl font-bold">
        Turno: {isCircleTurn ? "O" : "X"}
      </div>

      {/* Tabuleiro */}
      <div
        className="board grid place-items-center place-content-center
        [grid-template-columns:repeat(3,_100px)]
        [&>*]:border-[2px] [&>*]:border-white
        [&>*:nth-child(1)]:border-t-0 [&>*:nth-child(2)]:border-t-0 [&>*:nth-child(3)]:border-t-0
        [&>*:nth-child(1)]:border-l-0 [&>*:nth-child(4)]:border-l-0 [&>*:nth-child(7)]:border-l-0
        [&>*:nth-child(3)]:border-r-0 [&>*:nth-child(6)]:border-r-0 [&>*:nth-child(9)]:border-r-0
        [&>*:nth-child(7)]:border-b-0 [&>*:nth-child(8)]:border-b-0 [&>*:nth-child(9)]:border-b-0"
      >
        {Array(9)
          .fill(null)
          .map((_, i) => (
            <Cell key={i} value={board[i]} onPlay={() => handlePlay(i)} />
          ))}
      </div>

      <WinningMessage
        show={gameOver}
        message={winnerMessage}
        resetGame={resetGame}
      />
    </div>
  );
}

export default App;
