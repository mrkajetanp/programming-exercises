
def transform(legacy_data):
    result = {}

    for key in legacy_data:
        for c in legacy_data[key]:
            result[c.lower()] = key

    return result
