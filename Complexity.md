# Online Judges

Geralmente é dado 1 segundo máximo de tempo de execução para cada problema, mas isso pode variar de acordo com o problema.

desse modo, 1 segundo é equivalente a 10^8 operações dentro do seu código.

- Analise os casos de teste com base na complexidade que desejada para o seu código.

## Exemplo

A entrada máxima é 10^4, caso seu algoritmo seja O(n^2), o seu código não passará no teste de tempo porque 10^4 * 10^4 = 10^8, que é o limite de tempo. uma entrada superior a isso fará seu código demorar mais que 1 segundo para ser executado.

## Tabela Worst Case de complexidade com exemplo

De acordo com a entrada, qual complexidade aceitável e exemplo de problema comum.

| Entrada (N) |      Worst Case      |        Algoritmo Exemplo         |
| :---------: | :------------------: | :------------------------------: |
|    < 11     |    O(n!), O(n^6)     |            Permutação            |
|    < 18     |     O(2^n x n^2)     |    Dynamic Programming + TSP     |
|    < 400    |        O(n^3)        |          Floyd-Warshall          |
|    < 2K     |     O(n^2 log n)     |   Nested loop + Binary Search    |
|    < 10K    |        O(n^2)        |     Nested loop, bubblesort      |
|    < 1M     |      O(n log n)      |      Merge Sort, Quick Sort      |
|   <= 100M   | O(n), O(log n), O(1) | Linear Search, too many problems |
