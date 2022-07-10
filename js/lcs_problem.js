//https://www.hackerrank.com/challenges/common-child/problem

//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem


function commonChild(s1, s2) {
    let res = 0;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    let m = s1.length;
    let n = s2.length;
    let matc = new Array(m);
    for (let i = 0; i < m; i++) {
        matc[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            matc[i][j] = 0;
        }
    }
    for (let r = 1; r < m; r++) {
        for (let c = 1; c < n; c++) {
            if (s1[r] == s2[c]) {
                matc[r][c] = matc[r - 1][c - 1] + 1;
            } else {
                matc[r][c] = (matc[r][c - 1] > matc[r - 1][c]) ? matc[r][c - 1] : matc[r - 1][c];
            }
        }
    }
    console.log(matc);
    return matc[m-1][n-1];
}

commonChild("ABCDEF", "FBDAMN");