import psutil

def get_network_usage():
    process_list = []
    
    for proc in psutil.process_iter(['pid', 'name', 'io_counters', 'connections']):
        try:
            net_io = proc.info['io_counters']  # Network usage (if available)
            if net_io:
                connections = proc.info['connections']
                bytes_sent = sum(conn.raddr[1] if conn.raddr else 0 for conn in connections)
                bytes_recv = sum(conn.laddr[1] if conn.laddr else 0 for conn in connections)
                process_list.append((proc.info['pid'], proc.info['name'], bytes_sent, bytes_recv))
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            continue
    
    # Sort processes by received bytes
    process_list.sort(key=lambda x: x[3], reverse=True)

    print(f"{'PID':<10}{'Process Name':<25}{'Bytes Sent':<15}{'Bytes Received'}")
    for pid, name, sent, recv in process_list:
        print(f"{pid:<10}{name:<25}{sent:<15}{recv}")

get_network_usage()
