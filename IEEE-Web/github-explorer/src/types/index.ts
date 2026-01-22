export interface UserProps {
    login: string;
    avatar_url:string;
    name: string; 
    bio: string | null;
    followers: number;
    public_repos: number;
}

export interface RepoProps {
    id: number;
    name: string;
    description: string | null;
    html_url: string;
    language: string;
}