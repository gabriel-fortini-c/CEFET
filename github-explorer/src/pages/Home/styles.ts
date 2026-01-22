import styled from "styled-components";

export const Container = styled.div`
  width: 950px;
  background-color: #000000;
  padding: 40px 20px;

  margin: 0 auto;
`;

export const Title = styled.h1`
  font-size: 36px;
  color: #fffb14;
  max-width: auto;
`;

export const Form = styled.form`
  margin-top: 40px;
  width: auto;
  display: flex;

  input {
    flex: 1;
    font-size: 14px;
    height: auto;
    padding: 10px;
    border: 0;
    border-radius: 10px 0px 0px 10px;
    background-color: #ffffff;

    &::placeholder {
      color: #000000;
    }
  }

  button {
    width: 120px;
    height: auto;
    font-size: 14px;
    font-weight: bold;
    background-color: #fffb14;
    border-radius: 0 10px 10px 0;
    border: 0;
    color: #000000;
    transition: background-color 0.2s;

    &:hover {
      background-color: #fffb14da;
    }
  }
`;

export const Profile = styled.div`
  margin-top: 40px;

  header {
    background: white;
    display: flex;
    align-items: center;
    border-radius: 10px;

    img {
      width: 100px;
      height: 100px;
    }

    div {
      margin-left: 18px;

      strong {
        font-size; 36px;
        color: #3d3d4d
      }

      p {
        font-size: 18px;
        color: #737380;
        margin-top: 8px;
      }
    }
  }

  ul {
    display: flex;
    list-style: none;
    margin-top: 8px;
    color: #ffffff;

    li {
      margin-right: 20px;

      strong {
        display: block;
        font-size: 30px;
        color: #ffffff;
      }

      span {
        display: block;
        margin-top: 2px;
        color: #ffffff;
      }
    }

  }
`;

export const Repositories = styled.div`
  margin-top: 40px;
  max-width: auto;
  background: #ffffff;
  border-radius: 15px;

  a {
    width: 100%;
    padding: 15px 25px;
    text-decoration: none;

    display: flex;
    align-items: center;
    transition: transform 0.2s;

    &:hover {
      transform: translateX(4px);
    }

    & + a {
      margin-top: 12px;
    }

    div {
      flex: 1;

      strong {
        font-size: 18px;
        font-weight: bold;
        color: #000000;
      }

      p {
        font-size: 16px;
        color: #737380;
        margin-top: 2px;
      }
    }
  }
`;
