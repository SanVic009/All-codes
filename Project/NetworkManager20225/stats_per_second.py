import psutil
import time

def get_network_usage():
    usage = {}

    for proc in psutil.process_iter(['pid', 'name']):
        try:
            connections = proc.connections(kind='inet')  # Get only network-related connections
            sent = 0
            recv = 0

            if connections:  # If process has active connections
                net_io = psutil.net_io_counters(pernic=True)  # Get per-interface data
                for conn in connections:
                    iface = conn.laddr.ip  # Get local interface
                    if iface in net_io:
                        sent += net_io[iface].bytes_sent
                        recv += net_io[iface].bytes_recv

                usage[proc.info['pid']] = {
                    'name': proc.info['name'],
                    'bytes_sent': sent,
                    'bytes_recv': recv
                }
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            continue

    return usage

print("Monitoring Wi-Fi usage per process...\n")

while True:
    initial_usage = get_network_usage()
    time.sleep(1)  # Wait for 1 second
    final_usage = get_network_usage()

    print(f"{'PID':<10}{'Process Name':<25}{'Bytes Sent/sec':<15}{'Bytes Received/sec'}")
    for pid in final_usage:
        if pid in initial_usage:
            sent_per_sec = final_usage[pid]['bytes_sent'] - initial_usage[pid]['bytes_sent']
            recv_per_sec = final_usage[pid]['bytes_recv'] - initial_usage[pid]['bytes_recv']
            print(f"{pid:<10}{final_usage[pid]['name']:<25}{sent_per_sec:<15}{recv_per_sec}")

    print("-" * 60)
    time.sleep(2)  # Update every 2 seconds
