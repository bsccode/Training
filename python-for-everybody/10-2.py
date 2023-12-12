file = open("mbox-short.txt")
hour_counts = {}

for line in file:
    if line.startswith("From "):
        words = line.split()
        time = words[5]
        hour = time.split(":")[0]
        hour_counts[hour] = hour_counts.get(hour, 0) + 1
hour_list = sorted(hour_counts.items())

for hour, count in hour_list:
    print(hour, count)
    
    