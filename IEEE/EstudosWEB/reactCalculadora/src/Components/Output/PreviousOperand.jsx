function PreviousOperand({ previous, operation }) {
  return (
    <>
      <div className="text-[rgba(0,0,0,0.5)]">
        {previous} {operation}
      </div>
    </>
  );
}

export default PreviousOperand;
