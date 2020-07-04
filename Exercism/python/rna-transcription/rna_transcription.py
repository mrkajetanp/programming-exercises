def to_rna(dna_strand):
    rnas = { 'C': 'G', 'G': 'C', 'T': 'A', 'A': 'U' }
    return "".join([rnas[c] for c in dna_strand])
