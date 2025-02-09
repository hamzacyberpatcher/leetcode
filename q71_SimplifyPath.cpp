class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.replace("//","/")
        directories = path.split("/")
        path_list = []
        for directory in directories:
            if (directory != ".." and directory != "" and directory != "."):
                path_list.append(directory)
            elif directory == ".." and len(path_list) != 0:
                path_list.pop()
        path = ""
        for folder in path_list:
            path += f"/{folder}"
        if len(path_list) == 0: path = "/"
        return path
