import { useState, type FormEvent } from "react";
import api from "../../services/api";
import type { UserProps, RepoProps } from "../../types";

import { Container, Title, Form, Profile, Repositories } from "./styles";

export function Home() {
  const [user, setUser] = useState<UserProps | null>(null);
  const [repos, setRepos] = useState<RepoProps[]>([]);

  const [username, setUsername] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  async function handleSearch(event: React.FormEvent) {
    event.preventDefault();

    setError("");
    setUser(null);
    setRepos([]);
    setLoading(true);

    try {
      const [userData, repoData] = await Promise.all([
        api.get(`/users/${username}`),
        api.get(`/users/${username}/repos`),
      ]);

      setUser(userData.data);
      setRepos(repoData.data);
    } catch (err) {
      setError("Usuário não encontrado ou erro na conexão.");
    } finally {
      setLoading(false);
    }
  }

  return (
    <Container>
      <Title>Explore usuários no GitHub</Title>

      {/* O Form gerencia o Enter e o Clique no botão automaticamente */}
      <Form onSubmit={handleSearch}>
        <input
          placeholder="Digite o nome do usuário"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />
        <button type="submit">{loading ? "Carregando..." : "Pesquisar"}</button>
      </Form>

      {error && <p style={{ color: "#c53030", marginTop: "10px" }}>{error}</p>}

      {user && (
        <Profile>
          <header>
            <img src={user.avatar_url} alt={user.name} />
            <div>
              <strong>{user.name}</strong>
              <p>{user.bio}</p>
            </div>
          </header>
          <ul>
            <li>
              <strong>{user.followers}</strong>
              <span>Seguidores</span>
            </li>
            <li>
              <strong>{user.public_repos}</strong>
              <span>Repositórios</span>
            </li>
          </ul>
        </Profile>
      )}

      <Repositories>
        {repos.map((repo) => (
          // Transformei em link (a) para poder clicar e ir pro GitHub
          <a
            key={repo.id}
            href={repo.html_url}
            target="_blank"
            rel="noreferrer"
          >
            <div>
              <strong>{repo.name}</strong>
              <p>{repo.description}</p>
            </div>
          </a>
        ))}
      </Repositories>
    </Container>
  );
}
