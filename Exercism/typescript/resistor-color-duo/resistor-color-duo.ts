export class ResistorColor {
  private colors: string[];

  private values: string[] = [
    "black","brown","red","orange","yellow","green","blue","violet","grey","white"
  ];

  constructor(colors: string[]) {
    if (colors.length < 2)
      throw Error("At least two colors need to be present");

    this.colors = colors;
  }

  value = (): number => {
    return parseInt(
      `${this.values.indexOf(this.colors[0])}${this.values.indexOf(this.colors[1])}`
    );
  }
}
