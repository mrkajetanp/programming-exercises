//
// This is only a SKELETON file for the 'Raindrops' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const convert = (x) => {
  let result = "";

  if (x%3 == 0)
    result += "Pling";

  if (x%5 == 0)
    result += "Plang";

  if (x%7 == 0)
    result += "Plong";

  if (result.length == 0)
    result += x.toString();

  return result;
};
