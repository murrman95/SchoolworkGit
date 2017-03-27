typedef struct trie{
  char c;
  int key;
  struct trie *next;
  struct trie *child;
} Trie_T, *Trie_Pt;