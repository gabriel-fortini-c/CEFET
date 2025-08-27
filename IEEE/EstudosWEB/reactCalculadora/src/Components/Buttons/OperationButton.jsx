function OperationButton({ value, onClick }) {
  return (
    <button
      className="cursor-pointer text-[2rem] border-none outline-none bg-[rgb(80,80,80)] text-[white] hover:bg-[rgb(59,59,59)]"
      onClick={() => onClick(value)}
    >
      {value}
    </button>
  );
}

export default OperationButton;
