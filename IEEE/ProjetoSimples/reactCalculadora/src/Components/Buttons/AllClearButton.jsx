function AllClearButton({ value, onClick }) {
  return (
    <button
      className="cursor-pointer text-[2rem] border-none outline-none bg-[grey] text-[white] col-span-2 hover:bg-[rgb(90,90,90)]"
      onClick={() => onClick(value)}
    >
      {value}
    </button>
  );
}

export default AllClearButton;
