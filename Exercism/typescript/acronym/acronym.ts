export default class Acronym {
  public static parse(phrase: string): string {
    return phrase.replace("-", " ").replace(/([a-z])([A-Z])/, "$1 $2")
      .split(" ").map((it: string) => it[0]).join("").toUpperCase();
  }
}
