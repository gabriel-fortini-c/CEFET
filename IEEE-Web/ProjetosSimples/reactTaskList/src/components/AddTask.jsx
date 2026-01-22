import { useState } from "react";
import "./addtask.css";

function AddTask({ onAddSubmit }) {
  const [title, setTitle] = useState("");
  const [description, setDescription] = useState("");

  return (
    <div className="addTaskContainer">
      <input
        className="inputTitle"
        type="text"
        placeholder="Digite o título da tarefa"
        value={title}
        onChange={(event) => setTitle(event.target.value)}
      />
      <input
        className="inputDescription"
        type="text"
        placeholder="Digite a descrição da tarefa"
        value={description}
        onChange={(event) => setDescription(event.target.value)}
      />
      <button
        onClick={() => {
          if (!title.trim() || !description.trim()) {
            return alert("Preencha  o título e a descrição da tarefa.");
          }

          onAddSubmit(title, description);
          setTitle("");
          setDescription("");
        }}
        className="addButton"
      >
        Adicionar
      </button>
    </div>
  );
}

export default AddTask;
