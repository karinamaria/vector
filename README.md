# Introdução
O objetivo desse projeto é implementar o `vetor` da biblioteca stl do c++.
Vetores são contêiners sequenciais, que permite que os elementos poddem ser acessados e percorridos por iteradores.

# Compilação

Para compilar esse projeto com o [cmake](https://cmake.org) siga os passos:

1. `cd edb1`: entra no diretório principal do projeto
2. `cmake -S . -Bbuild`:  O cmake cria um diretório build e gera um Makefile baseado no script encontrado em `CMakeLists.txt` 
3. `cd build`: entra no diretório `build`
5. `cmake --build .` or `make`: aciona o processo de compilação

Os executáveis estarão no diretório `build`


# Execução

Os testes foram feitos usando o [Google tests](https://github.com/google/googletest/blob/master/googletest/docs/primer.md), faça o download na máquina de execução. E execute:

```
$ ./build/run_tests
```



# Discentes

- Karina Maria
- Maria Eduarda 