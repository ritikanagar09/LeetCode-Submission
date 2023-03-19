class Trie{
//samaj k chapo
public:
bool end;
Trie* child[26];
Trie(){
for(int i=0;i<26;i++){
child[i]=NULL;
}
end=false;
}
};
class WordDictionary {
public:
Trie* root;
WordDictionary() {
root=new Trie();
}

void addWord(string word) {
    Trie* temp=root;
    for(int i=0;i<word.size();i++){
        int num=word[i]-'a';
        if(temp->child[num]==NULL){
            temp->child[num]=new Trie();
        }
        temp=temp->child[num];
    }
    temp->end=true;
}
bool exist(Trie* temp,string &word,int index){
    if(index==word.size()){
        return temp->end;
    }

    if(word[index]=='.'){
        for(int i=0;i<26;i++){
            if(temp->child[i] && exist(temp->child[i],word,index+1)){
                return true;
            }
        }
    }
    else{
        int num=word[index]-'a';
        if(temp->child[num] && exist(temp->child[num],word,index+1)){
            return true;
        }
    }
    return false;
}
bool search(string word) {
    Trie* temp=root;
    if(exist(temp,word,0)){
        return true;
    }
    return false;
}
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */