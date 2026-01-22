import { createGlobalStyle } from "styled-components";

export const GlobalStyle = createGlobalStyle`
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
  }

  body {
    background-color: #f0f2f5;
    color: #333;
    -webkit-font-smoothing: antialiased;
    font-family: 'Roboto', sans-serif; /* Certifique-se de importar a fonte no index.html */
  }

  button {
    cursor: pointer;
  }
`;
