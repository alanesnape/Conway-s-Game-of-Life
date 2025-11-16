# Conway-s-Game-of-Life
This repository contains a clean implementation of John Conway's classic cellular automaton, enabling interactive visualization of evolving cell patterns./此存储库包含了约翰·康威经典细胞自动机的精简实现版本，能够实现细胞模式演变的交互式可视化展示。

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine./《生命游戏》（也简称为“生命”）是由英国数学家约翰·霍顿·康威于 1970 年设计的一种细胞自动机。这是一款零玩家游戏，即其演变过程仅由初始状态决定，无需进一步输入。玩家通过创建初始配置并观察其演变来与《生命游戏》互动。它具有图灵完备性，能够模拟通用构造器或任何其他图灵机。

The rules, which compare the behavior of the automaton to real life, can be condensed into the following:
Any live cell with two or three live neighbours survives.
Any dead cell with three live neighbours becomes a live cell.
All other live cells die in the next generation. Similarly, all other dead cells stay dead.
这些规则将自动机的行为与现实生活进行了对比，可以概括为以下内容：
任何有两个或三个活细胞相邻的活细胞将继续存活。
任何没有活细胞相邻但有三个活细胞的死细胞将变成活细胞。
在下一代中，所有其他活细胞都将死亡。同样，所有其他死细胞将保持不变（即继续处于死亡状态）。
