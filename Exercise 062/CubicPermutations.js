

cubeOrdered = [];
for(var i=0;true;i++){
	var cube = String(i*i*i);
	var o = cube.split('');
	o.sort();
	var p = o.join('')
	if(cubeOrdered[p] == undefined){
		cubeOrdered[p] = [];
	}
	cubeOrdered[p].push(cube);
	if(cubeOrdered[p].length>=5){
		trace(cubeOrdered[p]);
		break;
	}
}