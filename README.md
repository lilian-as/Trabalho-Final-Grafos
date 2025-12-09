# 🎉 Festa Perfeita com Coloração de Grafos

Este projeto implementa em **C** uma analogia divertida do problema de **Coloração de Grafos**: organizar convidados em mesas de uma festa, garantindo que pessoas em conflito não fiquem juntas.

---

## 🚀 Como compilar e executar

1. Compile o código:
   ```bash
   gcc festa_grafos.c -o festa
2. Execute:
   bash
   ./festa

4. Informe os dados solicitados (quantidade de convidados de cada tipo e número de mesas).

📋 Regras da Festa
   Cada mesa comporta no máximo 4 pessoas.
   Conflitos:

   Policiais × Bandidos
   Devedores × Agiotas
   Flamenguistas × Vascaínos
   Ex1 × Ex2
   Fofoqueiros × Vítimas

Se não houver mesas suficientes para acomodar todos sem conflitos, o programa informa que é impossível organizar.

🧩 Estrutura do Código

adicionar_convidado: adiciona um convidado à lista.
adicionar_conflito: marca que dois convidados não podem sentar juntos.
organizar_festa: distribui convidados nas mesas usando uma heurística gulosa.
imprimir_mesas: mostra a distribuição final.

📚 Exemplo de uso
   
   Digite o numero maximo de mesas: 10
   Quantos policias e bandidos? 3 4
   Quantos devedores e agiotas? 3 4
   Quantos torcedores do flamengo e do vasco? 5 5
   Quantos ex1 e ex2? 2 2
   Quantos fofoqueiros e vitimas? 1 3
   
   Saída:
   
    Convidados organizados
   Mesa 1:  Policial_1  Policial_2  Policial_3  Devedor_1 
   Mesa 2:  Bandido_1  Bandido_2  Bandido_3  Bandido_4 
   Mesa 3:  Devedor_2  Devedor_3  Flamenguista_1  Flamenguista_2 
   Mesa 4:  Agiota_1  Agiota_2  Agiota_3  Agiota_4 
   Mesa 5:  Flamenguista_3  Flamenguista_4  Flamenguista_5  Ex1_1 
   Mesa 6:  Vascaino_1  Vascaino_2  Vascaino_3  Vascaino_4 
   Mesa 7:  Vascaino_5  Ex1_2  Fofoqueiro_1 
   Mesa 8:  Ex2_1  Ex2_2  Vitima_1  Vitima_2 
   Mesa 9:  Vitima_3 

    mesas que sobraram: 1
