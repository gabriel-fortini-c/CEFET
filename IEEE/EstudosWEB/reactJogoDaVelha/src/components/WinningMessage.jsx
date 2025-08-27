function WinningMessage({ show, message, resetGame }) {
  return (
    <>
      <div
        className={`${show ? "flex" : "hidden"} 
        fixed top-0 left-0 right-0 bottom-0 justify-center items-center bg-[rgba(0,0,0,0.65)] flex-col`}
      >
        <p className="text-white text-[5rem]">{message}</p>
        <button
          className="text-black text-[2.5rem] bg-white px-2.5 py-4 cursor-pointer rounded-[5px] border-none mt-[16px]"
          onClick={resetGame}
        >
          Reiniciar
        </button>
      </div>
    </>
  );
}

export default WinningMessage;
