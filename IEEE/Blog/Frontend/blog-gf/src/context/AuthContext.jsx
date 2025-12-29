import { createContext, useState, useContext } from "react";

const AuthContext = createContext();

export const AuthProvider = ({ children }) => {
  const [authUser, setAuthUser] = useState(() => {
    try {
      const savedUser = localStorage.getItem("authUser");
      // Se encontramos um usuário salvo, usamos ele.
      // JSON.parse transforma o texto de volta em um objeto.
      return savedUser ? JSON.parse(savedUser) : null;
    } catch (error) {
      console.error("Failed to parse auth user from localStorage", error);
      return null;
    }
  });

  const login = (userData) => {
    console.log("Logando usuário: ", userData);
    setAuthUser(userData);

    // Nós salvamos o usuário no localStorage como texto.
    // JSON.stringify transforma o objeto em texto.
    localStorage.setItem("authUser", JSON.stringify(userData));
  };

  const logout = () => {
    console.log("Deslogando usuário");
    setAuthUser(null);

    // Nós removemos o usuário do localStorage.
    localStorage.removeItem("authUser");
  };

  const value = {
    authUser,
    login,
    logout,
  };

  return <AuthContext.Provider value={value}>{children}</AuthContext.Provider>;
};

export const useAuth = () => {
  return useContext(AuthContext);
};
