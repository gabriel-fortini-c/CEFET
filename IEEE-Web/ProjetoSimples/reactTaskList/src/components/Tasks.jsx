import { useNavigate } from "react-router-dom";
import "./tasks.css";
import { Check, ChevronRightIcon, TrashIcon } from "lucide-react";

function Tasks({ tasks, onTaskClick, onDeleteTaskClick }) {
  const navigate = useNavigate();

  function onSeeDetailsClick(task) {
    const query = new URLSearchParams();
    query.set("title", task.title);
    query.set("description", task.description);
    navigate(`/taskDetails?${query.toString()}`);
  }

  return (
    <ul className="taskContainer">
      {tasks.map((task) => (
        <li key={task.id} className="task">
          <button
            onClick={() => onTaskClick(task.id)}
            className={`taskButton ${task.isCompleted ? "line-through" : ""}`}
          >
            {task.isCompleted ? <Check className="checkButton" /> : ""}
            {task.title}
          </button>

          <button
            onClick={() => onSeeDetailsClick(task)}
            className="detailButton"
          >
            <ChevronRightIcon />
          </button>

          <button
            onClick={() => onDeleteTaskClick(task.id)}
            className="deleteButton"
          >
            <TrashIcon />
          </button>
        </li>
      ))}
    </ul>
  );
}

export default Tasks;
