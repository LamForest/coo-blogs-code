
double get_time_stamp_us()
{
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    return (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(end.time_since_epoch())
                        .count()) /
           1000.f;
}

double get_time_stamp()
{
    return get_time_stamp_us() / 1000.f;
}

#define TIME_START(tag)                            \
    double time_##tag##_start = get_time_stamp();  \
    double time_##tag##_end = time_##tag##_start;  \
    double time_##tag##_node = time_##tag##_start; \
    ((void)(time_##tag##_end));                    \
    ((void)(time_##tag##_node));

#define TIME_END(tag)                    \
    time_##tag##_end = get_time_stamp(); \
    printf("[Profile] - [%-15s] costs %lf ms\n", #tag, time_##tag##_end - time_##tag##_start);

#define TIME_NODE(tag, node)                                                         \
    double time_##tag##node = get_time_stamp();                                      \
    LOGD("[%s.%s] costs %lf ms", #tag, #node, time_##tag##node - time_##tag##_node); \
    time_##tag##_node = time_##tag##node;