<div align="center">
	<h1>🕋cub3D🕋</h1>
  "This project is inspired by the world-famous Wolfenstein 3D game, which is
considered the first FPS ever created. It will enable you to explore ray-casting. Your goal
will be to make a dynamic view inside a maze, where you will have to find your way."
  <br>   <br>

  <img src="https://raw.githubusercontent.com/fbkeskin/fbkeskin/master/spongebob.gif"/>
  
  <p align="center">
	<h4>My first RayCaster with miniLibX!<br>
    <br>
  </p></h4>
    	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<a href="https://developer.apple.com/library/archive/documentation/Performance/Conceptual/ManagingMemory/Articles/FindingLeaks.html"><img src="https://img.shields.io/badge/leaks-none-success" /></a>
	<img src="https://img.shields.io/badge/-100%2F125-success?logo=42&logoColor=fff" />
  <p align="center">
    <br>
    <i>This project’s objectives are similar to all this first year’s objectives: rigor, use of C, basic algorithms, information research, etc. <br>
        As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.<br>
In conclusion, cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics. With the help of numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.<br><br>
</i>
  </p>
  <br />

</div>

## 📝Usage
1. Repo'yu clone'layın: 

```bash
git clone https://github.com/fbkeskin/42-cub3D.git
```

2. Makefile'ı kullanarak source kodu derleyin:
> Unutmayın, mevcut MLX library yalnızca Linux machine'lerde çalışmaktadır.
```bash
make
```
> 1 executable file oluşmaktadır: `cub3D`.

3. Oynamak istediğiniz map'i argüman olarak girin ve `cub3D` binary dosyasını execute ederek programı başlatın:
> Projenin kök dizininde scene_description_files klasörü altında yer alan valid map'lerden birini tercih edebilirsiniz.
```shell
$>./cub3D scene_description_files/valid/works.cub

$>./cub3D scene_description_files/invalid/color_none.cub
Error
Element has incorrect type identifier!

$>./cub3D "map.buc" 
Error
not cub file

$>./cub3D life gave me some lemons so i made some lemonade
Error
The number of arguments must be 2!
```

> Program, bilgisayarınızda bir window açarak oyun arayüzünüz ile etkileşime geçmenizi sağlar. Amaç, 2D window üzerinde raycasting tekniğini kullanarak 3D bir görüntü elde etmektir. Oyuncu, labirent içinde dolaşır.

4. Farklı map files ile çalışmak için 3. adımı tekrarlayın.


## 📚MLX
MinilibX, öğrenciler için tasarlanmış, yeni başlayanlara uygun, C dilinde basit bir X-Window programlama API'sidir.<br>

Useful links:
* [Lode's Raycasting Document](https://lodev.org/cgtutor/raycasting.html)
* [Dounia's Medium Blogpost](https://medium.com/@rtailidounia/raycasting-in-cub3d-42-network-project-a-practical-tutorial-using-vectors-68eeb16b3de2)
* [Harm Smits - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX](https://github.com/42Paris/minilibx-linux)
* [Laura&Simon Gitbook](https://42-cursus.gitbook.io/guide/minilibx)


## 🎮CONTROLS
|KEYBOARD|ACTION|
|---|---|
|`W`|Move up|
|`S`|Move down|
|`A`|Move left|
|`D`|Move right|
|`>`|Rotate right|
|`<`|Rotate left|
|`ESC`, `❌`|Close the game window|




