// problem from :
// http://adventofcode.com/2018/day/1

/* ------------------ Read input part ------------------- */

function readInput() {
    var regex = /\d+/g;
    var fs = require('fs');
    var path = process.cwd();
    //var buffer = fs.readFileSync(path + "\\aoc3.txt"); //Windows
    var buffer = fs.readFileSync(path + "/aoc3.txt"); //Linux
    var respText = buffer.toString();
    var alltext = respText.match(regex);
    return alltext;
}

/* -------------------------------------------- */
var len = 1500;
var map = [];//new Array(len);
for (let i = 0; i < len; i++) {
    map[i] = [];//new Array(len);
    for (let j = 0; j < len; j++) {
        map[i][j] = {
            list:[]
        };
    }
}

function calcResult(strInputs) {
    let z = 0;
    while (z < strInputs.length) {
        let id = strInputs[z + 0];
        let left = parseInt(strInputs[z + 1]);
        let top = parseInt(strInputs[z + 2]);
        let w = parseInt(strInputs[z + 3]);
        let h = parseInt(strInputs[z + 4]);
        z += 5;
        for (let x = left + 1; x <= left + w; x++) {
            for (let y = top + 1; y <= top + h; y++) {
                map[x][y].list.push(id);
            }
        }
    }
}

var inputs = readInput();
calcResult(inputs);

function getIndex(obj, list) {
    var i;
    for (i = 0; i < list.length; i++) {
        if (list[i] === obj) {
            return i;
        }
    }
    return -1;
}

var res = 0;
var arSingle = [];
var arMulti = [];
for (let q = 0; q < len; q++) {
    for (let a = 0; a < len; a++) {
        let listLen = map[q][a].list.length;
        if (listLen > 1) {
            res++;
        }       
        for (let op = 0; op < listLen; op++) {
            let curId = map[q][a].list[op];
            let idx1 = getIndex(curId, arSingle);
            let idx2 = getIndex(curId, arMulti);
            if (listLen == 1) {
                if (idx2 == -1 && idx1 == -1) {
                    arSingle.push(curId);
                }
            } else if (listLen > 1) {                
                if (idx1 != -1) {
                    arSingle.splice(idx1, 1);
                }
                if (idx2 == -1) {
                    arMulti.push(curId);
                }
            }
        }
    }
}

console.log("Single: " + arSingle);
console.log("Result: " + res);