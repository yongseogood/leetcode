class FileSystem {
public:
    struct fileNode {
        unordered_map<string, fileNode*> next;
        bool isFile;
        string content;
        fileNode() : isFile(false), content("") {}
    };
    
    fileNode *root;

    FileSystem() {
        root = new fileNode();        
    }
    
    fileNode* goToPathFolder(string& path) {
        fileNode *cur = root;
        stringstream s(path);
        string folder;
            
        while(getline(s, folder, '/')) {
            if(folder.size()) {
                if(cur->next[folder] == nullptr)
                    cur->next[folder] = new fileNode();
                cur = cur->next[folder];
            }
        }
        
        return cur;
    }

    vector<string> ls(string path) {
        fileNode *cur = goToPathFolder(path);
        
        vector<string> res;

        if(cur->isFile) {
            res.push_back(path.substr(path.find_last_of('/') + 1));
            return res;            
        }
        
        for(auto &p : cur->next) {
            res.push_back(p.first);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        fileNode* cur = goToPathFolder(path);
    }
    
    void addContentToFile(string filePath, string content) {
        fileNode* cur = goToPathFolder(filePath);
        cur->content += content;
        cur->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        fileNode* cur = goToPathFolder(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
