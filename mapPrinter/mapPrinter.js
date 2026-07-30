const canvas = document.querySelector("canvas")
const context= canvas.getContext("2d")


const color = ["#032f67","#004bb4","#34baff","#04c2e3","#56e4e7","#fedc53","#ffbc53","#bf811b","#956316","#75b459","#169154","#575757","#656565","#a8a8a8","#bdbdbd","#ffffff"]
// const colorlow =  ["#032f67","#032f67","#032f67","#032f67", "#34baff","#34baff","#34baff","#75b459","#75b459", "#75b459","#75b459","#75b459","#656565","#656565","#656565","#656565"]

function printMap()
{
    const input = document.getElementById("input").value
    const map = input.trim().split(/\r?\n/).map(line => line.trim().split(/\s+/).map(Number))
    let posx = 0;
    let posy = 0;
    for (let y = 0; y < map.length; y++) {
        for (let x = 0; x < map.length; x++) {
            context.fillStyle = color[map[y][x]]
            context.fillRect(posx,posy, 10, 10);
            posx += 10;
        }
        posy +=10;
        posx = 0;
    }
}
// context.fillStyle = "red"
// context.fillRect(0, 0, 50, 50);