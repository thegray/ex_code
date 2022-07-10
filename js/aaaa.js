var test = [1,2,3,4,3,2,1]

console.log(test.length);
let len = test.length;

for (let i = 0; i < len; i++) {
	if (test[i] == test[len-i-1]) {
		console.log('sama');
	} else {
		console.log('tidak');
	}
}