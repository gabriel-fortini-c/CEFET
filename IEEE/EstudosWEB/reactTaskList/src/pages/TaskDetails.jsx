import { useNavigate, useSearchParams } from "react-router-dom";
import "./taskdetails.css";
import { ChevronLeftIcon } from "lucide-react";

function TaskDetails() {
  const [serchParams] = useSearchParams();
  const title = serchParams.get("title");
  const description = serchParams.get("description");

  const navigate = useNavigate();

  return (
    <div className="DetailContainer">
      <div className="DetailContent">
        <div className="DetailTitleContent">
          <button onClick={() => navigate(-1)} className="returnButton">
            <ChevronLeftIcon />
          </button>
          <h1 className="DetailTitle">Detalhes da Tarefa</h1>
        </div>

        <div className="DetailTask">
          <h2 className="taskTitle"> {title} </h2>
          <p className="taskDescription"> {description} </p>
        </div>
      </div>
    </div>
  );
}

export default TaskDetails;
