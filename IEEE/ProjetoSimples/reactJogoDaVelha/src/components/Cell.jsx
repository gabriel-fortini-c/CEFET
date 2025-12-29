import "./Cell.css";

function Cell({ className = "", value, onPlay }) {
  const handleClick = () => {
    if (!value) {
      onPlay();
    }
  };

  return (
    <div
      className={`w-[100px] h-[100px] flex justify-center items-center relative 
      ${className}
      ${value || ""}`}
      onClick={handleClick}
    ></div>
  );
}

export default Cell;
