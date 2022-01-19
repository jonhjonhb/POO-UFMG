//Considere o código a seguir, responda as seguintes questões e justifique sua resposta:

class Base{
    
    int i;
    
    protected:
        int read() const { return i; }
        void set(int ii) { i = ii; }
    
    public:
        Base(int ii = 0) : i(ii) {}
        int value(int m) const { return m*i; }
};


class Derived : public Base{
        
        int j;
        public:
            Derived(int jj = 0) : j(jj) {}
            void change(int x) { set(x); }
};

//  P:  É possível adicionar uma função membro na classe Derived que chama a função read()?
//  R:  Como a classe Derived utiliza a chamada de classe de origem como "Public", a função read() continua com nível de acesso protected, e como membros de nível protected podem ser 
//      acessados pela classe de origem e todas suas subclasses, a classe Derived pode sim chamar a função read().
//  
//  P:  Alterando a herança para private, ainda assim é possível adicionar uma função membro na classe Derived que chama a função read()?
//  R:  Não. Com uma herança em estado "private", todos os níveis de acesso menores que private são convertidos para o mesmo. Dessa forma, todos os membros public ou protected se tornam
//      inacessíveis na classe Derived.
//  
//  P:  É possível chamar a função read() a partir de um objeto do tipo Derived?
//  R:  Utilizando-se apenas do objeto em questão, não. A única forma de acessar um membro de nível de acesso protected é dentro da classe original, em classes derivadas com acesso ao 
//      mesmo, ou em classes que possuem um relacionamento de "Friend" com a classe de qual o membro se origina.
//  
//  P:  Modifique o código de forma que a classe Derived use herança protected. Crie uma classe Derived2 que seja derivada da classe Derived utilizando herança public. É possível chamar 
//      read() a partir de uma função membro da classe Derived2? E o método value()?
//  R:  Ambos são acessíveis em Derived2. Read() continua como protected, então pode ser acessada nas subclasses com acesso devido. Value() muda de public para protected, mas ainda é,
//      assim como read(), acessível.
//      Código modificado:

class Base{
    
    int i;
    
    protected:
        int read() const { return i; }
        void set(int ii) { i = ii; }
    
    public:
        Base(int ii = 0) : i(ii) {}
        int value(int m) const { return m*i; }
};


class Derived : protected Base{
        
        int j;
        public:
            Derived(int jj = 0) : j(jj) {}
            void change(int x) { set(x); }
};

class Derived2 : public Derived{
        
        int k;
        public:
            Derived2(int kk = 0) : k(kk) {}
            void change(int x) { set(x); }
};