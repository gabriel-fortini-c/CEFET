// Tarefas
class Task {
  constructor(title, description) {
    this.id = Date.now();
    this.title = title;
    this.description = description;
    this.isCompleted = false;
  }
}

// Montar a lista das tarefas no taskContainer
// Renderiza cada tarefa
const taskContainer = document.querySelector(".taskContainer");

function renderTasks() {
  taskContainer.innerHTML = ""; // Limpa a lista

  tasks.forEach((task) => {
    const li = document.createElement("li");
    li.classList.add("task");
    li.setAttribute("data-id", task.id); // coloca o ID no elemento

    // Botão da tarefa
    const titleBtn = document.createElement("button");
    titleBtn.classList.add("taskButton");
    titleBtn.addEventListener("click", () => {
      taskClick(task.id);
      renderTasks();
    });
    titleBtn.textContent = task.title;
    titleBtn.textContent = (task.isCompleted ? "✓ " : "") + task.title;
    if (task.isCompleted) {
      titleBtn.classList.add("line-through"); // se a tarefa está completa, adiciona a classe
    } else {
      titleBtn.classList.remove("line-through"); // se não está, garante que a classe não esteja
    }

    // Botão dos detalhes da tarefa
    const detailBtn = document.createElement("button");
    detailBtn.classList.add("detailButton");
    detailBtn.textContent = ">";
    detailBtn.addEventListener("click", () => {
      window.location.href = `detailPage.html?id=${task.id}`;
    });

    // Botão de deletar tarefas
    const deleteBtn = document.createElement("button");
    deleteBtn.classList.add("deleteButton");
    deleteBtn.textContent = "Apagar";
    deleteBtn.addEventListener("click", () => {
      removeTask(task.id);
      renderTasks();
    });

    li.appendChild(titleBtn);
    li.appendChild(detailBtn);
    li.appendChild(deleteBtn);
    taskContainer.appendChild(li);
  });
}

// const tasks = [
//   {
//     id: 1,
//     title: "Estudar JavaScript",
//     description: "Revisar funções",
//     isCompleted: false,
//   },
//   {
//     id: 2,
//     title: "Ir à academia",
//     description: "Treino de pernas",
//     isCompleted: true,
//   },
// ];

// Adicionar Tarefas
let tasks = [];
renderTasks();

function addTask(title, description) {
  if (!title.trim() || !description.trim()) {
    return alert("Preencha  o título e a descrição da tarefa.");
  }
  tasks.push(new Task(title, description));

  saveTasks();
}

const addButton = document.querySelector("[add-button]");
const titleInput = document.getElementById("input-title");
const descriptionInput = document.getElementById("input-description");

addButton.addEventListener("click", () => {
  const titleValue = titleInput.value;
  const descriptionValue = descriptionInput.value;
  addTask(titleValue, descriptionValue);
  renderTasks();
  titleInput.value = "";
  descriptionInput.value = "";
});

// Remover Tarefas
function removeTask(id) {
  tasks = tasks.filter((task) => task.id !== id);

  saveTasks();
  renderTasks();
}

// Detalhes da Tarefa
function taskClick(taskId) {
  tasks = tasks.map((task) => {
    if (task.id === taskId) {
      return {
        ...task,
        isCompleted: !task.isCompleted,
      };
    }
    return task;
  });

  saveTasks();
  renderTasks();
}

function saveTasks() {
  localStorage.setItem("tasks", JSON.stringify(tasks));
}

function loadTasks() {
  const saved = localStorage.getItem("tasks");
  if (saved) {
    tasks = JSON.parse(saved);
  } else {
    tasks = []; // se não houver nada salvo
  }
  renderTasks();
}

loadTasks();
