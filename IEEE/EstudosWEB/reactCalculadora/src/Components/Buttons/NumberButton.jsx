function NumberButton({ value, onClick }) {
  return (
    <button
      className={`cursor-pointer text-[2rem] border-none outline-none 
      bg-[grey] text-[white] hover:bg-[rgb(90,90,90)] 
      ${value === "." ? "col-span-2" : ""}`}
      onClick={() => onClick(value)}
    >
      {value}
    </button>
  );
}

export default NumberButton;
