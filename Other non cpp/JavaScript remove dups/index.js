String.prototype.replaceAt=function(index, character) {
    return this.substr(0, index) + character + this.substr(index+character.length);
}
function swap(input, index1, index2){
    if(index1===index2){
        return input;
    }
    
    var tmp = input[index1];
    //input[index1] = input[index2];
    input = input.replaceAt(index1, input[index2])    
    //input[index2] = tmp;
    input = input.replaceAt(index2, tmp);
	return input;
}
function removeDuplicateChars(input) {
    // COMPLETE ME
    // warning: writing to process.stdin will break scoring
    // Note: The `input` variable holds the string to remove characters from.
    // This function does not need any parameters, and should return a string.
    var len = input.length;
    // todo test empty string
    
    var index, index2, curChar;
    for(index=0; index<len; index++){
        curChar = input[index];
        //console.log("curChar", curChar);
        for(index2 = len-1; index2>index; index2--){
            if(input[index2] === curChar){
                //console.log("Elements match at indices:", index2, index);
				//console.log("Before swap: ", input);
                input = swap(input, index2, len-1);
				//console.log("After swap:  ", input);
                len--;
                //console.log("new length", len);
            }
        }
    }
    return input.substr(0, len);
}
removeDuplicateChars("ac");
removeDuplicateChars("acac");