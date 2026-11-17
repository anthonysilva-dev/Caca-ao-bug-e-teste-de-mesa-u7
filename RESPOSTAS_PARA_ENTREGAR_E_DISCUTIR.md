# Respostas da Parte B e Discussão Final (Unidade 7)

## L4. Ver os bytes de um `int` com uma `union`
* **Pergunta:** O primeiro byte impresso é `0x01` ou `0x04`? O que isso diz sobre como o seu computador guarda um `int` (little-endian)?
* **Resposta:** O primeiro byte impresso (`u.b[0]`) é **`0x04`**. Isso mostra que o computador utiliza arquitetura **little-endian**, na qual o byte menos significativo (`0x04` de `0x01020304`) é armazenado no menor endereço de memória, e o byte mais significativo (`0x01`) fica no maior endereço (`u.b[3]`).

---

## L5. Medir o padding com `sizeof` e `offsetof`
* **Pergunta:** Confira: `Ruim` dá 12 bytes; `Bom`, 8 — mesmos campos, só reordenados. Explique, pelos offsets, onde está o padding em cada caso.
* **Resposta:**
  * **`struct Ruim` (`sizeof` = 12 bytes):**
    * `a` (`char`, 1 byte) fica no **offset 0**.
    * Como `b` (`int`, 4 bytes) precisa começar em um endereço múltiplo de 4, o compilador insere **3 bytes de padding** nos offsets **1, 2 e 3**.
    * `b` fica nos offsets **4 a 7** (offset 4).
    * `c` (`char`, 1 byte) fica no **offset 8**.
    * Para que o tamanho total da estrutura seja múltiplo do seu maior alinhamento (4 bytes), são inseridos mais **3 bytes de padding no final** (offsets **9, 10 e 11**), fechando em **12 bytes**.
  * **`struct Bom` (`sizeof` = 8 bytes):**
    * `b` (`int`, 4 bytes) fica nos offsets **0 a 3** (offset 0).
    * `a` (`char`, 1 byte) entra logo em seguida no **offset 4**.
    * `c` (`char`, 1 byte) entra no **offset 5** (sem padding entre `b`, `a` e `c`).
    * Restam apenas **2 bytes de padding no final** (offsets **6 e 7**) para fechar um múltiplo de 4, totalizando **8 bytes**.

---

## Para discutir no fim
* **Pergunta:** Quais bugs o compilador pega sozinho (itens 2, 4, 6)? Quais só aparecem ao raciocinar sobre a memória (itens 7, 8) ou ao rodar (item 11 vira warning)?
* **Resposta:**
  * **Pego pelo compilador (erro de compilação):**
    * **Item 2:** tentar usar `.` em vez de `->` em um ponteiro para `struct`.
    * **Item 4:** tentar comparar duas `structs` diretamente com o operador `==`.
    * **Item 6:** tentar acessar um campo de uma `struct` interna (`c.numero`) sem passar pelo campo intermediário (`c.ender.numero`).
  * **Só aparece ao raciocinar sobre a memória (compila sem erro nem warning):**
    * **Item 7:** sobreposição de bytes em uma `union` e leitura parcial dependente de *little-endian*.
    * **Item 8:** escrever um `int` e ler um `float` na mesma `union`, reinterpretando os mesmos bits no padrão IEEE 754 em vez de converter o valor numérico.
  * **Aparece ao rodar / gera warning na compilação:**
    * **Item 11:** retornar o endereço de uma variável local (`return &p;`). O compilador emite um *warning* (`-Wreturn-local-addr`), e em tempo de execução ocorre comportamento indefinido (leitura de memória inválida na *stack*).
