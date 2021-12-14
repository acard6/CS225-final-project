file = open("routes.csv").readlines()
file[0] = file[0][3:]

output = []

for i in range(0, len(file)):
    if not file[i][10] == '0' and not file[i][12] == '0':
        output.append(file[i])

out = open("output.csv", 'a').writelines(output)