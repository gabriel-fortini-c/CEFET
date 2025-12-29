import { useState } from "react";
import Output from "./components/Output/Output";
import AllClearButton from "./Components/Buttons/AllClearButton";
import DeleteButton from "./Components/Buttons/DeleteButton";
import NumberButton from "./Components/Buttons/NumberButton";
import OperationButton from "./Components/Buttons/OperationButton";

function App() {
  const [currentOperand, setCurrentOperand] = useState("");
  const [previousOperand, setPreviousOperand] = useState("");
  const [operation, setOperation] = useState(null);

  function appendNumber(number) {
    if (number === "." && currentOperand.includes(".")) return;

    setCurrentOperand(currentOperand + number.toString());
  }

  function chooseOperation(op) {
    if (currentOperand === "") return;

    if (previousOperand !== "") {
      calculate();
    } else {
      setPreviousOperand(currentOperand);
      setCurrentOperand("");
    }
    setOperation(op);
  }

  function calculate() {
    const prev = parseFloat(previousOperand);
    const current = parseFloat(currentOperand);

    if (isNaN(prev) || isNaN(current)) return;

    let result;
    switch (operation) {
      case "+":
        result = prev + current;
        break;
      case "-":
        result = prev - current;
        break;
      case "÷":
        result = prev / current;
        break;
      case "*":
        result = prev * current;
        break;
      default:
        return;
    }

    // result = formatDisplayNumber(result);

    setCurrentOperand(result.toString());
    setOperation(null);
    setPreviousOperand("");
  }

  function clear() {
    setCurrentOperand("");
    setPreviousOperand("");
    setOperation(undefined);
  }

  function deleteDigit() {
    setCurrentOperand(currentOperand.toString().slice(0, -1));
  }

  // function formatDisplayNumber(number) {
  //   const stringNumber = number.toString();

  //   const intergerDigits = parseFloat(stringNumber.split(".")[0]);
  //   const decimalDigits = stringNumber.split(".")[1];

  //   let integerDisplay;

  //   if (isNaN(intergerDigits)) {
  //     integerDisplay = "";
  //   } else {
  //     integerDisplay = intergerDigits.toLocaleString("en", {
  //       maximumFractionDigits: 0,
  //     });
  //   }

  //   if (decimalDigits != null) {
  //     return `${integerDisplay}.${decimalDigits}`;
  //   } else {
  //     return integerDisplay;
  //   }
  // }

  return (
    <>
      <div
        className="grid justify-center content-center min-h-screen 
          [grid-template-columns:repeat(4,_100px)] 
          [grid-template-rows:minmax(120px,_auto)_repeat(5,_100px)]"
      >
        <Output
          previous={previousOperand}
          current={currentOperand}
          operation={operation}
        />
        <AllClearButton value="AC" onClick={() => clear()} />
        <DeleteButton value="DEL" onClick={() => deleteDigit()} />
        <OperationButton value="÷" onClick={() => chooseOperation("÷")} />
        <NumberButton value="1" onClick={() => appendNumber("1")} />
        <NumberButton value="2" onClick={() => appendNumber("2")} />
        <NumberButton value="3" onClick={() => appendNumber("3")} />
        <OperationButton value="*" onClick={() => chooseOperation("*")} />
        <NumberButton value="4" onClick={() => appendNumber("4")} />
        <NumberButton value="5" onClick={() => appendNumber("5")} />
        <NumberButton value="6" onClick={() => appendNumber("6")} />
        <OperationButton value="+" onClick={() => chooseOperation("+")} />
        <NumberButton value="7" onClick={() => appendNumber("7")} />
        <NumberButton value="8" onClick={() => appendNumber("8")} />
        <NumberButton value="9" onClick={() => appendNumber("9")} />
        <OperationButton value="-" onClick={() => chooseOperation("-")} />
        <NumberButton value="." onClick={() => appendNumber(".")} />
        <NumberButton value="0" onClick={() => appendNumber("0")} />
        <OperationButton value="=" onClick={() => calculate()} />
      </div>
    </>
  );
}

export default App;
