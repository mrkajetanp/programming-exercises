//
// This is only a SKELETON file for the 'Resistor Color Duo' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const COLOURS = ["black","brown","red","orange","yellow","green","blue","violet","grey","white"];

export const decodedValue = (colours) => {
  return parseInt(COLOURS.indexOf(colours[0]).toString().concat(COLOURS.indexOf(colours[1]).toString()));
};
