const params = new URLSearchParams(window.location.search);
const taskId = params.get("id");

const tasks = JSON.parse(localStorage.getItem("tasks")) || [];

const task = tasks.find((t) => t.id == taskId);

if (task) {
  document.getElementById("task-title").textContent = `${task.title}:`;
  document.getElementById("task-description").textContent =
    task.description || "Sem descrição";
} else {
  document.body.innerHTML = "<p>Tarefa não encontrada</p>";
}

document.querySelector(".returnButton").addEventListener("click", () => {
  window.history.back();
});
