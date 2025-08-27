import CurrentOperand from "./CurrentOperand";
import PreviousOperand from "./PreviousOperand";

function Output({ previous, current, operation }) {
  return (
    <>
      <div
        className="col-span-full bg-[#c6c6c6]
        flex flex-col items-end justify-around [padding:_10px;]
        break-words break-all"
      >
        <PreviousOperand previous={previous} operation={operation} />
        <CurrentOperand current={current} />
      </div>
    </>
  );
}

export default Output;
